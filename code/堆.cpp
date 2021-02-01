void siftdown(int a[], int i, int n){
    int j, t=a[i];
    while((j=2*i+1)<n){
        if(j<n-1 && a[j]<a[j+1])
            j++;
        if(t<a[j]){
            a[i] = a[j];
            i = j;
        }
        else
            break;
    }
    a[i] = t;
}//在以a[i]为根的二叉树中确定a[i]的位置

void heap(int a[], int n){
    int i;
    for(i=(n-1)/2; i>=0; --i)
        siftdown(a, i, n);//调整为堆
}

void heap_sort(int a[], int n){
    int i, t;
    heap(a, n);
    for(i=n-1; i>0; --i){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        siftdown(a, 0, i);
    }
}

void siftup(int a[], int k){
    int j=k, i=(j-1)/2, t=a[j];
    while(j>0)
        if(a[i]>=t)
            break;
        else{
            a[j] = a[i]; 
            j = i; 
            i = (i-1)/2;
        }
    a[j] = t;
}//新元素放在a[k]中