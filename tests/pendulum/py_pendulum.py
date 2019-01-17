import unittest

from libpy_pendulum import InvertedPendulum


class TestInvertedPendulum(unittest.TestCase):
    def test_inverted_pendulum(self):
        name = 'test inverted_pendulum'
        ip = InvertedPendulum(name)

        self.assertEqual(ip.name, name)


if __name__ == '__main__':
    unittest.main()
