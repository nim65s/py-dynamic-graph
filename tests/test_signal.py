import unittest

from libpy_dynamic_graph import SignalBase


class TestSignal(unittest.TestCase):
    def test_signal_base(self):
        name = 'test signal base'
        signal = SignalBase(name)

        self.assertEqual(signal.name, name)

        self.assertEqual(signal.time, 0)
        signal.time += 42
        self.assertEqual(signal.time, 42)

        self.assertFalse(signal.ready)

        self.assertEqual(signal.period_time, 1)

        # setPeriodTime is pure virtual in SignalBase
        # signal.period_time = 10
        # self.assertEqual(signal.period_time, 10)

        other_signal = SignalBase('other')

        signal.add_dependency(other_signal)
        signal.remove_dependency(other_signal)
        signal.clear_dependencies()

        self.assertFalse(signal.is_plugged())
        with self.assertRaises(Exception):
            signal.plug(other_signal)
        with self.assertRaises(Exception):
            signal.unplug()
        with self.assertRaises(Exception):
            signal.set_constant_default()


if __name__ == '__main__':
    unittest.main()
