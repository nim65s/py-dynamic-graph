import unittest

from libpy_dynamic_graph import Entity


class TestEntity(unittest.TestCase):
    def test_entity(self):
        name = 'test entity'
        entity = Entity(name)

        self.assertEqual(entity.name, name)

        # getClassName is pure virtual
        # entity.class_name

        self.assertEqual(entity.docstring, 'No header documentation.')

        self.assertFalse(entity.has_signal('nothing'))


if __name__ == '__main__':
    unittest.main()
