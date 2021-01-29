# -*- coding: utf-8 -*-
import pytest

from pybind11_tests import open_spiel_pattern as m

def test_make_and_use_foo():
    res = m.make_and_use_foo(lambda : m.Foo(123))
    assert res == 579
