#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

DistanceMatrix FileManager::readMatrixFromFile(const string& fileName)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << fileName << endl;
        // Thực hiện xử lý lỗi cụ thể ở đây nếu muốn, ví dụ: trả về một DistanceMatrix mặc định hoặc ném một ngoại lệ
    }

    int size;
    file >> size; // Đọc kích thước của ma trận
    if (size <= 0) {
        cerr << "Error: Invalid matrix size " << size << endl;
        // Thực hiện xử lý lỗi cụ thể ở đây nếu muốn, ví dụ: trả về một DistanceMatrix mặc định hoặc ném một ngoại lệ
    }

    DistanceMatrix matrix(size);

    // Đọc dữ liệu từ file và thiết lập cho ma trận
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double distance;
            file >> distance;
            matrix.setDistance(i, j, distance);
        }
    }

    return matrix;
}
