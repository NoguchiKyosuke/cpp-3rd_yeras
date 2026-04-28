#include <stdio.h>
#include "svg.h"

class Circle { 
private:
    int x, y;
    int rad;
    svg* svgObj;
    int N;

public:
    Circle (); // 関数の内容は記述しない
    Circle (int cx, int cy, int r = 10);
    void setPosition (int x, int y);
    void setRadius (int rad);
    void getPosition (int xy[]); // 追加。配列pに座標を代入する。
    void getRadius ();
    void draw (svg* svgObj, int N);
};

class ColorCircle {
private: // 非公開
    int x, y, rad; // 中心座標と半径
    std::string color; // 描画色（標準ライブラリの文字列）

public: // 公開
    ColorCircle (); // 構築子
    ColorCircle (int cx, int cy, int r, std::string c); // 違う形式の構築子

    void setPosition (int x, int y);
    void setRadius (int rad);
    int getRadius ();
    void draw (svg* svgObj);
    void setColor (std::string); // 色の設定
};
