void mo() {
    int B = W / sqrt(Q);
    vector<int> ord(Q);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
	    // ブロックが違うなら，小さい方から
        if(L[i] / B != L[j] / B) return L[i] / B < L[j] / B;
        
        // ブロックが同じなら，上(もしくは下)から
        if((L[i] / B) % 2) return R[i] > R[j];
        return R[i] < R[j];
    });
    
    int cur_l = 0, cur_r = 0;
    for(int i : ord) {
		while(cur_l > L[i]) add_l(--l);
		while(cur_l < L[i]) rem_l(l++);
		while(cur_r > R[i]) rem_r(--r);
		while(cur_r < R[i]) add_r(r++);
		
		ans[i] = calc();
    }
}