// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>
#include <pybind11/pytypes.h>
#include <vector>
#include <complex>
#include <iostream>
#if defined(_OPENMP)
#include <omp.h>
#endif
#include "simulator.hpp"

namespace py = pybind11;

using c_type = std::complex<double>;
using ArrayType = std::vector<c_type, aligned_allocator<c_type,64>>;
using MatrixType = std::vector<ArrayType>;
using QuRegs = std::vector<std::vector<unsigned>>;

PYBIND11_MODULE(_cppsim, m)
{
    py::class_<Simulator>(m, "Simulator")
        .def(py::init<unsigned>())
        .def("apply_controlled_gate", &Simulator::apply_controlled_gate<MatrixType>)
        .def("get_expectation_value", &Simulator::get_expectation_value)
        .def("apply_qubit_operator", &Simulator::apply_qubit_operator)
        .def("emulate_time_evolution", &Simulator::emulate_time_evolution)
        .def("set_wavefunction", &Simulator::set_wavefunction)
        .def("run", &Simulator::run)
        .def("cheat", &Simulator::cheat)
        ;
}
