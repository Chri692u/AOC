NB. Read inputs
input =: ". , 'm' freads './inputs/6.txt'

NB. Solution to part 1

NB. Replace any index below 0
replace =: {{ 6 (I. 0>y) } y }}

oneDay =: {{ 
	if. 0 e. y do.
		(replace y-1) , (+/y=0) $ 8
	else.
		y-1	
	end.
}}

days =: 80
solution = #(oneDay^:80 input) 
