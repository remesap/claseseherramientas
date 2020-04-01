set key b r
set xlabel "x"
set ylabel "y"
set title "Lagrange polinomials "
set term pdf
set out "1.pdf"
plot "datos.txt" u 1:2 w l t "P(n)"

