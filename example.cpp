// build all -> python setup.py build_ext --inplace

#include <pybind11/pybind11.h>

// this enables automatic conversion between python lists and c++ STL containers (vectors)
#include <pybind11/stl.h>
#include <vector>
#include <cmath>

float distance(const std::vector<uint8_t> &a, const std::vector<uint8_t> &b)
{
    return (sqrt(pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2) + pow((a[2] - b[2]), 2)));
}

std::vector<std::vector<std::vector<uint8_t>>> choose_colors(std::vector<std::vector<std::vector<uint8_t>>> &image, std::vector<std::vector<uint8_t>> &color_vector)
{
    for (size_t width = 0; width < image.size(); width++)
    {
        for (size_t height = 0; height < image[width].size(); height++)
        {
            float current_min_distance = 9999;
            for (size_t i = 0; i < color_vector.size(); i++)
            {
                float current_distance = distance(image[width][height], color_vector[i]);
                size_t color_index = 0;
                if (current_distance <= current_min_distance)
                {
                    current_min_distance = current_distance;
                    color_index = i;
                }
                image[width][height] = color_vector[i];
            }
            
        }
    }

    return image;
}

// std::vector is a dynamically sized array
// cosnt -> i promise not to modify the data in the function
//  "&" after vector<..> pass by reference, wount be copied into the functon, original data will be modified
int process_image(const std::vector<std::vector<std::vector<uint8_t>>> &image)
{
    size_t height = image.size();
    size_t width = image.size();
    size_t channels = image.size();

    return height;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("process_image", &process_image, "A function to process an image");
    m.def("choose_colors", &choose_colors, "choose colors");
}