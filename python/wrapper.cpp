#include <pybind11/pybind11.h>
#include "../cpp/tinyTransfer.h"

PYBIND11_MODULE(pytinytransfer,m) {
    m.doc() = "Python bindings for tinytransfer";

    m.def("fletcher16", &fletcher16, "Checksum calculation algorithm");
}