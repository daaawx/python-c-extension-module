import fputs
import pytest

def test_module_data():
    assert fputs.__doc__ == "Python interface for the fputs C library function"
    assert fputs.__name__ == "fputs"

def test_constant_exists():
    assert fputs.FPUTS_FLAG == 64

def test_fputs():
    with pytest.raises(ValueError):
        fputs.fputs("Python!", "output.txt")

    fputs.fputs("Python!!!!!", "output.txt")
    with open("output.txt", "r") as f:
        data = f.read()

    assert data == "Python!!!!!"

