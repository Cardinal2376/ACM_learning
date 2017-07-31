sort(vecs.begin(), vecs.end());
vecs.resize(unique(vecs.begin(), vecs.end()) - vecs.begin());