greedy:
	g++ greedy.cpp SumofGaussians.cpp -o greedy
	g++ sa.cpp SumofGaussians.cpp -o sa
clean:
	rm -f greedy
	rm -f sa
