#include "svg.h"

std::ofstream svg::ofs; // クラス変数ofsの定義

void svg::open(std::string filename, int width, int height) {
    svg::ofs.open(filename);
    svg::ofs << "<?xml version='1.0'?>" << std::endl;
    svg::ofs << "<svg xmlns='http://www.w3.org/2000/svg' width='" << width << "' height='" << height << "'>" << std::endl;
}

// SVGドキュメントを閉じる（自動的にファイル保存される）
void svg::close() {
    svg::ofs << "</svg>";
    svg::ofs.close();
}

void svg::drawCircle(int cx, int cy, int r, std::string color, int stroke_width) {
    if (stroke_width > 0) {
        svg::ofs <<  "<circle cx='" << cx << "' cy='" << cy << "' r='" << r
        << "' stroke='" << color << "' stroke-width='" << stroke_width << "' fill='none'/>" << std::endl;
    } else {
        svg::ofs <<  "<circle cx='" << cx << "' cy='" << cy << "' r='" << r
        << "' fill='" << color + "'/>" << std::endl;
    }
}

void svg::drawRect(int x, int y, int width, int height) {
    ofs <<  "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height
        << "' fill='black' />" << std::endl;
}

void svg::drawText(int x, int y, std::string label) {
    ofs << "<text x='" << x << "' y='" << y << "'>" << std::endl; // 開始タグ
    ofs << label; // 描画テキスト
    ofs << "</text>"; // 終了タグ
}    
