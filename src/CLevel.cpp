#include "CLevel.h"

using namespace std;

CLevel::CLevel(int width, int height) : m_Width(width), m_Height(height) {
}

void CLevel::draw(CRenderer &renderer) const {
    for (auto &brick: m_Bricks) {
        if (!brick.isDestroyed())
            brick.draw(renderer.getRenderer());
    }
}

void CLevel::load(const char *filePath) {

    ifstream srcStream(filePath, ios::binary);
    if (!srcStream || !srcStream.is_open())
        throw runtime_error("FAILED TO OPEN LEVEL FILE");

    vector<vector<int>> data;
    string line;
    while (getline(srcStream, line)) {
        vector<int> row;
        int number;
        stringstream ss(line);
        while (ss >> number) {
            if (number > 4 || number < 0)
                throw runtime_error("INVALID LEVEL FILE SYNTAX: UNKNOWN BRICK CODE");
            row.push_back(number);
        }

        data.push_back(row);
    }

    if (data.empty())
        throw runtime_error("INVALID LEVEL FILE SYNTAX: FILE EMTPY");

    if (all_of(data.begin(), data.end(), [](const vector<int> &row) {
        return all_of(row.begin(), row.end(), [](int x) { return x == 0; });
    }))
        throw runtime_error("INVALID LEVEL FILE SYNTAX");

    size_t rowLength = data[0].size();
    if (!all_of(data.begin(), data.end(), [rowLength](auto &row) { return row.size() == rowLength; }))
        throw runtime_error("INVALID LEVEL FILE SYNTAX: ROWS NOT EQUAL");

    convertData(data);
}

void CLevel::convertData(std::vector<std::vector<int>> data) {
    int brickHeight = m_Height / data.size();
    if(brickHeight <= 10)
        throw runtime_error("INVALID LEVEL FILE SYNTAX: TOO MANY ROWS");
    int brickWidth = m_Width / data[0].size();
    if(brickWidth <= 20)
        throw runtime_error("INVALID LEVEL FILE SYNTAX: TOO MANY COLUMNS");

    for (int i = 0; i < static_cast<int>(data.size()); ++i) {
        for (int j = 0; j < static_cast<int>(data[0].size()); ++j) {
            if (data[i][j] == 1) {
                CBrick brick(CCoords{j * brickWidth, i * brickHeight}, brickWidth,
                             brickHeight, CColor{68, 85, 150}, false, 5);
                m_Bricks.push_back(brick);
            } else if (data[i][j] == 2) {
                CBrick brick(CCoords{j * brickWidth, i * brickHeight}, brickWidth,
                             brickHeight, CColor{0, 126, 0}, false, 10);
                m_Bricks.push_back(brick);
            } else if (data[i][j] == 3) {
                CBrick brick(CCoords{j * brickWidth, i * brickHeight}, brickWidth,
                             brickHeight, CColor{200, 57, 46}, false, 50);
                m_Bricks.push_back(brick);
            } else if (data[i][j] == 4) {
                CBrick brick(CCoords{j * brickWidth, i * brickHeight}, brickWidth,
                             brickHeight, CColor{100, 100, 100}, true);
                m_Bricks.push_back(brick);
            } else if (data[i][j] == 0) {
                CBrick brick(CCoords{j * brickWidth, i * brickHeight}, brickWidth,
                             brickHeight, CColor{0, 0, 0}, true);
                brick.setDestroyed(true);
                m_Bricks.push_back(brick);
            }
        }
    }
}

std::vector<CBrick> &CLevel::getBricks() {
    return m_Bricks;
}

bool CLevel::isCompleted() const {
    return all_of(m_Bricks.begin(), m_Bricks.end(), [](auto &brick) { return brick.isDestroyed() || brick.isSolid(); });
}

void CLevel::resetBricks() {
    for (auto &brick: m_Bricks) {
        if (!(brick.getColor().r == 0 && brick.getColor().g == 0 && brick.getColor().b == 0))
            brick.setDestroyed(false);
    }
}



