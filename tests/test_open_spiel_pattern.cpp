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

using FooFactory = std::function<Foo()>;

int MakeAndUseFoo(FooFactory f) {
    auto foo = f();
    return foo.bar(456);
}

} // namespace open_spiel_pattern
} // namespace pybind11_tests

// To use py::smart_holder, uncomment the next line and change py::class_ below to py::classh.
// PYBIND11_SMART_HOLDER_TYPE_CASTERS(pybind11_tests::open_spiel_pattern::Foo)

TEST_SUBMODULE(open_spiel_pattern, m) {
    using namespace pybind11_tests::open_spiel_pattern;

    py::class_<Foo>(m, "Foo").def(py::init<int>()).def("bar", &Foo::bar);

    m.def("make_and_use_foo", MakeAndUseFoo);
}
