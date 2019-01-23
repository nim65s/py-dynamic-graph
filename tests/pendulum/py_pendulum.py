import unittest
from collections import OrderedDict

from libpy_pendulum import InvertedPendulum, SignalBase

MEMBERS = OrderedDict([('cart_mass', 4.2), ('pendulum_mass', 2.3), ('pendulum_length', 0.8), ('viscosity', 0.5)])


class TestInvertedPendulum(unittest.TestCase):
    def test_inverted_pendulum(self):
        name = 'test inverted_pendulum'
        ip = InvertedPendulum(name)

        self.assertEqual(ip.name, name)
        self.assertEqual(ip.class_name, 'InvertedPendulum')
        self.assertEqual(ip.docstring, 'Classical inverted pendulum dynamic model\n')

        for member, value in MEMBERS.items():
            setattr(ip, member, value)
            self.assertEqual(getattr(ip, member), value)

        for _ in range(100):
            ip.incr(1e-3)

        self.assertTrue(ip.has_signal('state'))
        self.assertTrue(ip.has_signal('force'))
        self.assertFalse(ip.has_signal('plop'))

        ip2 = InvertedPendulum(name + '2', *MEMBERS.values())
        for member, value in MEMBERS.items():
            self.assertEqual(getattr(ip2, member), value)

        force_in = ip.force
        self.assertTrue(isinstance(force_in, SignalBase))
        self.assertEqual(force_in.time, 0)

        # state_out = ip.state
        # self.assertTrue(isistance(state_out, SignalBase))


if __name__ == '__main__':
    unittest.main()
