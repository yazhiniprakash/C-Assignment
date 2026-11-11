File: pipeline.cppm

export module pipeline;



import <vector>;

import <concepts>;

import <ranges>;



export template <typename T>

concept Numeric = std::integral<T> || std::floating_point<T>;


export template <Numeric T>

std::vector<T> processData(const std::vector<T>& data)

{

    std::vector<T> result;



    auto pipeline = data

        | std::views::filter([](T value) {
             return value > 0;

        })

        | std::views::transform([](T value) {

             return value * 2;

        });



    for (T value : pipeline)

    {

        result.push_back(value);

    }



    return result;

}

File: main.cpp

import pipeline;


#include <iostream>

#include <vector>

using namespace std;


int main()

{

    vector<int> data = {-5, 10, 20, -3, 15, 30};



    vector<int> result = processData(data);



    cout << "Original Data: ";


    for (int value : data)

    {

        cout << value << " ";

    }

    cout << "\nProcessed Data: ";



    for (int value : result)

    {

        cout << value << " ";

    }

    cout << endl;

    return 0;

}

File: CMakeLists.txt

cmake_minimum_required(VERSION 3.20)


project(DataPipeline)



set(CMAKE_CXX_STANDARD 20)


set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(DataPipeline

    main.cpp

    pipeline.cppm

)
OUTPUT:
Original Data: -5 10 20 -3 15 30
Processed Data: 20 40 30 60
