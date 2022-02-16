#include "CScoreBoard.h"

using namespace std;

CScoreBoard::CScoreBoard(int width, int height) : m_Width(width), m_Height(height) {

}

void CScoreBoard::addScore(size_t score) {
    m_CurrentScore = score;
    if (find(m_ScoreList.begin(), m_ScoreList.end(), score) == m_ScoreList.end()) {
        auto it = lower_bound(m_ScoreList.begin(), m_ScoreList.end(), score, greater<>());
        m_ScoreList.insert(it, score);
    }
}

void CScoreBoard::draw(SDL_Renderer *renderer) const {
    string score = "SCORE";
    string top = "TOP 3";
    string currentScore = to_string(m_CurrentScore);
    string top1 = to_string(m_ScoreList[0]);
    string top2 = to_string(m_ScoreList[1]);
    string top3 = to_string(m_ScoreList[2]);
    vector<CLetter> letters;

    int letterHeight = m_Height / 10;
    int letterWidth = m_Width / 12;
    int gap = m_Width / 80;


    for (int i = 0; i < static_cast<int>(score.size()); ++i)
        letters.emplace_back(CCoords{10 + (i * (letterWidth + gap)), gap}, letterWidth, letterHeight, CColor{0, 0, 0},
                             score[i]);

    for (int i = 0; i < static_cast<int>(currentScore.size()); ++i)
        letters.emplace_back(CCoords{m_Width - 4 * gap - 4 * letterWidth + i * (letterWidth + gap), 10}, letterWidth,
                             letterHeight, CColor{0, 0, 0}, currentScore[i]);

    for (int i = 0; i < static_cast<int>(top.size()); ++i)
        letters.emplace_back(CCoords{10 + (i * (letterWidth + gap)), 5 * gap + letterHeight}, letterWidth, letterHeight,
                             CColor{0, 0, 0}, top[i]);

    for (int i = 0; i < static_cast<int>(top1.size()); ++i)
        letters.emplace_back(
                CCoords{m_Width - 4 * gap - 4 * letterWidth + i * (letterWidth + gap), 5 * gap + letterHeight},
                letterWidth, letterHeight, CColor{0, 0, 0}, top1[i]);

    for (int i = 0; i < static_cast<int>(top2.size()); ++i)
        letters.emplace_back(
                CCoords{m_Width - 4 * gap - 4 * letterWidth + i * (letterWidth + gap), 2 * (5 * gap + letterHeight)},
                letterWidth, letterHeight, CColor{0, 0, 0}, top2[i]);

    for (int i = 0; i < static_cast<int>(top3.size()); ++i)
        letters.emplace_back(
                CCoords{m_Width - 4 * gap - 4 * letterWidth + i * (letterWidth + gap), 3 * (5 * gap + letterHeight)},
                letterWidth, letterHeight, CColor{0, 0, 0}, top3[i]);

    for (auto &letter: letters)
        letter.draw(renderer);
}

void CScoreBoard::save(const char *filePath) {
    ofstream dstStream(filePath, ios::binary);
    if (!dstStream || !dstStream.is_open())
        throw runtime_error("FAILED TO OPEN SCORE FILE");

    for (auto &score : m_ScoreList)
        dstStream << score << endl;
}

void CScoreBoard::load(const char *filePath) {
    ifstream srcStream(filePath, ios::binary);
    if (!srcStream || !srcStream.is_open())
        throw runtime_error("FAILED TO OPEN SCORE FILE");

    string line;
    while (getline(srcStream, line)) {
        size_t score = 0;
        stringstream ss(line);
        ss >> score;
        if (score && score < 10000 && score >= 0)
            addScore(score);
    }
}
