#include "pybind11_tests.h"

#include <pybind11/functional.h>
#include <pybind11/smart_holder.h>

#include <functional>

namespace pybind11_tests {
namespace open_spiel_pattern {

class Foo {
public:
    int num;
    Foo(int i) : num{i} {}
    int bar(int i) { return num + i; }
};

} // namespace open_spiel_pattern
} // namespace pybind11_tests

PYBIND11_SMART_HOLDER_TYPE_CASTERS(pybind11_tests::open_spiel_pattern::Foo)

namespace pybind11_tests {
namespace open_spiel_pattern {

int RecycleFoo() {
    Foo foo_orig(123);
    py::object foo_py = py::cast(foo_orig);
    auto foo_from_py  = py::cast<std::unique_ptr<Foo>>(foo_py);
    return foo_from_py->bar(456);
}

} // namespace open_spiel_pattern
} // namespace pybind11_tests

TEST_SUBMODULE(open_spiel_pattern, m) {
    using namespace pybind11_tests::open_spiel_pattern;

    py::classh<Foo>(m, "Foo");

    m.def("recycle_foo", RecycleFoo);
}
