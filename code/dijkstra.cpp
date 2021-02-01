priority_queue<pair<int,int> >q;
void dijkstra()
{
    memset(dist,127,sizeof(dist));
    dist[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(v[x])
            continue;
        v[x]=1;
        for(int i=head[x];i;i=nxt[i])
        {
            int y=to[i];
            if(dist[y]>dist[x]+val[i])
            {
                dist[y]=dist[x]+val[i];
                q.push(make_pair(-dist[y],y));
            }
        }
    }
}