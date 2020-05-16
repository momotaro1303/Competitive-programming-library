//めぐる式2分探索
/*
return okなら条件を満たす最小のindexを返す
return ngなら条件を満たさない最大のindexを返す
*/
bool isOK(ll index, ll key) {
	if(index<0) return false;
	if(index>N-1) return true;
    if (a[index] >= key) return true;
    else return false;
}
ll bin_search(ll key) {
    ll ng=-1; 
    ll ok=(ll)a.size(); 
    while (abs(ok-ng)>1) {
        ll mid=(ok+ng)/2;
        if (isOK(mid,key)) ok=mid;
        else ng=mid;
    }
    return ok;
}