set term pdf
set out '1.pdf'
set xlabel 'n'
set ylabel 'Delta'
set log y
plot 'datos.txt'  w lp
