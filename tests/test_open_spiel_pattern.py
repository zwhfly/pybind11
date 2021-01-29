# -*- coding: utf-8 -*-
import pytest

from pybind11_tests import open_spiel_pattern as m


def test_recycle_foo():
    res = m.recycle_foo()
    assert res == 579
