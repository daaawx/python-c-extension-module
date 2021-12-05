#include <Python.h>

static PyObject *method_fputs(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parsing args from C */
    if (!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    /* Raising exception from C */
    if (strlen(str) < 10) {
        PyErr_SetString(PyExc_ValueError, "String length must be greater 10");
        return NULL;
    }

    FILE *fp = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);
}

static PyMethodDef FputsMethods[] = {
    {"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C library function"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef fputsmodule = {
    PyModuleDef_HEAD_INIT,
    "fputs",
    "Python interface for the fputs C library function",
    -1,
    FputsMethods
};

PyMODINIT_FUNC PyInit_fputs(void) {
    PyObject *module = PyModule_Create(&fputsmodule);

    // Add int constant
    PyModule_AddIntConstant(module, "FPUTS_FLAG", 64);
    return module;
}
