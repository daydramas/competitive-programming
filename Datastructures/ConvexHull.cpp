int orientation(ii p, ii q, ii r) { 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
} 
  
// Prints convex hull of a set of n points. 
vii convexHull(vii points) { 
    if (n < 3) return; 
    vector<ii> hull; 
  
    // Find the leftmost point 
    int l=0; 
    for (int i=1; i<sz(points); i++) 
        if (points[i].x < points[l].x)  l = i; 
  
    int p = l, q; 
    do { 
        hull.push_back(points[p]); 
        q = (p+1)%n; 
        for0(i, sz(points)) { 
           if (orientation(points[p], points[i], points[q])==2) 
               q = i; 
        } 
        p=q; 
  
    } while (p!=l);  
  
    return hull;
} 