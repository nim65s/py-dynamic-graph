import unittest

from libpy_pendulum import InvertedPendulum

MEMBERS = {'cart_mass': 4.2, 'pendulum_mass': 2.3, 'pendulum_length': 0.8, 'viscosity': 0.5}


class TestInvertedPendulum(unittest.TestCase):
    def test_inverted_pendulum(self):
        name = 'test inverted_pendulum'
        ip = InvertedPendulum(name)

        self.assertEqual(ip.name, name)

        for member, value in MEMBERS.items():
            setattr(ip, member, value)
            self.assertEqual(getattr(ip, member), value)

        ip2 = InvertedPendulum(name + '2', *MEMBERS.values())
        for member, value in MEMBERS.items():
            self.assertEqual(getattr(ip2, member), value)


if __name__ == '__main__':
    unittest.main()
