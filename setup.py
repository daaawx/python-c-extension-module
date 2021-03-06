from distutils.core import setup, Extension

def main():
    setup(
            name="fputs",
            version="1.0.0",
            description="Python interface for the fputs C library",
            author="Dax",
            author_email="dario@mory.dev",
            ext_modules=[
                Extension("fputs", ["fputsmodule.c"])
                ]
            )


if __name__ == "__main__":
    main()

