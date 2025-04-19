// build all -> python setup.py build_ext --inplace

#include <pybind11/pybind11.h>

// this enables automatic conversion between python lists and c++ STL containers (vectors)
#include <pybind11/stl.h>
#include <vector>
#include <cmath>

int add(int i, int j)
{
    return i + j;
}

int sub(int i, int j)
{
    return i - j;
}

std::vector<std::vector<std::vector<uint8_t> > > choose_colors(std::vector<std::vector<std::vector<uint8_t> > > &image)
{

    image[0][0] = {200, 10, 100};

    return image;
}

// std::vector is a dynamically sized array
// cosnt -> i promise not to modify the data in the function
//  "&" after vector<..> pass by reference, wount be copied into the functon, original data will be modified
int process_image(const std::vector<std::vector<std::vector<uint8_t> > > &image)
{
    size_t height = image.size();
    size_t width = image.size();
    size_t channels = image.size();

    return height;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("sub", &sub, "A function that subs two numbers");
    m.def("process_image", &process_image, "A function to process an image");
    m.def("choose_colors", &choose_colors, "choose colors");
}