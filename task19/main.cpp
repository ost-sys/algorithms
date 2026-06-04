#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>

void writeFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream f(filename);
    for (int i = 0; i < (int)data.size(); ++i) {
        if (i > 0) f << ' ';
        f << data[i];
    }
}

std::vector<int> readFile(const std::string& filename) {
    std::ifstream f(filename);
    std::vector<int> data;
    int x;
    while (f >> x) data.push_back(x);
    return data;
}

void splitToFiles(const std::string& src,
                  const std::string& fileB,
                  const std::string& fileC,
                  int step) {
    std::vector<int> data = readFile(src);
    int n = (int)data.size();
    std::vector<int> bData, cData;
    int i = 0;
    bool toggle = true;
    while (i < n) {
        int end = std::min(i + step, n);
        std::vector<int>& target = toggle ? bData : cData;
        for (int j = i; j < end; ++j)
            target.push_back(data[j]);
        toggle = !toggle;
        i += step;
    }
    writeFile(fileB, bData);
    writeFile(fileC, cData);
}

void mergeFiles(const std::string& fileB,
                const std::string& fileC,
                const std::string& dst,
                int step) {
    std::vector<int> b = readFile(fileB);
    std::vector<int> c = readFile(fileC);
    std::vector<int> result;
    int ib = 0, ic = 0;
    int nb = (int)b.size(), nc = (int)c.size();

    while (ib < nb || ic < nc) {
        int bEnd = std::min(ib + step, nb);
        int cEnd = std::min(ic + step, nc);
        int bi = ib, ci = ic;

        while (bi < bEnd && ci < cEnd) {
            if (b[bi] <= c[ci]) result.push_back(b[bi++]);
            else                 result.push_back(c[ci++]);
        }
        while (bi < bEnd) result.push_back(b[bi++]);
        while (ci < cEnd) result.push_back(c[ci++]);

        ib += step;
        ic += step;
    }
    writeFile(dst, result);
}

void straightMergeSortExternal(const std::string& inputFile,
                               const std::string& outputFile) {
    std::vector<int> data = readFile(inputFile);
    int n = (int)data.size();
    writeFile(outputFile, data);

    const std::string fileB = "temp_b.txt";
    const std::string fileC = "temp_c.txt";

    for (int step = 1; step < n; step *= 2) {
        splitToFiles(outputFile, fileB, fileC, step);
        mergeFiles(fileB, fileC, outputFile, step);
    }

    std::remove(fileB.c_str());
    std::remove(fileC.c_str());
}

int main() {
    std::ofstream in("input.txt");
    in << "5 3 8 1 9 2 7 4 6";
    in.close();

    straightMergeSortExternal("input.txt", "output.txt");

    std::vector<int> result = readFile("output.txt");
    std::cout << "Результат: ";
    for (int x : result) std::cout << x << ' ';
    std::cout << std::endl;
    return 0;
}