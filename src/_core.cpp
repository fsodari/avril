#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

std::string hello_from_bin() { return "Hello, Avril!"; }

namespace nb = nanobind;

NB_MODULE(_core, m)
{
  m.doc() = "nanobind hello module";

  m.def("hello_from_bin", &hello_from_bin);
}
