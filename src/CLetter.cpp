#include "CLetter.h"

CLetter::CLetter(CCoords pos, size_t width, size_t height, CColor color, char character) : CObject(pos, width, height,
                                                                                                   color){
    if (character == 'B') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
    }
    if (character == 'R') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
    }
    if (character == 'P') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
    }
    if (character == 'E') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
    }

    if (character == 'A') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height - 20});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});

    }
    if (character == 'O' || character == '0') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
    }

    if (character == 'U') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
    }

    if (character == 'T') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    }
    if (character == 'S' || character == '5') {
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
    }
    if (character == 'L') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
    }
    if (character == 'Y') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height / 3});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height / 3});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    }
    if (character == 'K') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
    }
    if (character == ' ') {

    }
    if (character == 'C') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
    }
    if (character == '1') {
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    }
    if (character == '2') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
    }
    if (character == '3') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width - 10, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
    }

    if (character == '4') {
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + 2 * m_Height / 3});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + 2 * m_Height / 3});
    }

    if (character == '6') {
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 3});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 3});
    }
    if (character == '7') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width / 2, m_Pos.m_Y + m_Height});
    }
    if (character == '8') {
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
    }

    if (character == '9') {
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height / 2});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y});
        m_Vertices.push_back(CCoords{m_Pos.m_X + m_Width, m_Pos.m_Y + m_Height});
    }
}

void CLetter::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, getColor().r, getColor().g, getColor().b, 255);
    if (!m_Vertices.empty()) {
        for (size_t i = 0; i < m_Vertices.size() - 1; ++i) {
            SDL_RenderDrawLine(renderer, m_Vertices[i].m_X, m_Vertices[i].m_Y,
                               m_Vertices[i + 1].m_X, m_Vertices[i + 1].m_Y);
        }
    }
}
