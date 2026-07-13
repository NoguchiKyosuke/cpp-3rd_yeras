# 1. 出力形式の設定 (PNG画像として保存、フォントとサイズを指定)
set terminal pngcairo size 800, 600 font "sans,12"
set output "graph.png"

# 2. グラフ全体の見た目の設定
set title "データの分布" font "sans,14"
set xlabel "X"
set ylabel "Y"
set grid                # グリッド線（目盛り線）を表示
set key left top        # 凡例を左上に配置

# 3. 軸の範囲の調整
set xrange [-15:15]
set yrange [-20:25]

# 4. プロットの実行
plot "data.txt" using 2:3 with lines linewidth 2 linecolor rgb "blue" title "生成値", "data.txt" using 4:5 with points pointtype 7 pointsize 1.0 linecolor rgb "red" title "ノイズデータ"