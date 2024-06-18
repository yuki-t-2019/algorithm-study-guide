/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: uft.cpp
 */

#include "src/uft.h"

UnionFind::UnionFind(int n) {
    parent_.resize(n + 1);
    rank_.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent_[i] = i;
        rank_[i] = 0;
    }
}

int UnionFind::Find(int x) {
    if (parent_[x] != x) {
        parent_[x] = Find(parent_[x]); // path compression
    }
    return parent_[x];
}

void UnionFind::Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX != rootY) {
        // union by rank
        if (rank_[rootX] > rank_[rootY]) {
            parent_[rootY] = rootX;
        } else if (rank_[rootX] < rank_[rootY]) {
            parent_[rootX] = rootY;
        } else {
            parent_[rootY] = rootX;
            rank_[rootX]++;
        }
    }
}

bool InputValidation(int N, int k) {
    return (MIN_N <= N && N <= MAX_N && MIN_K <= k && k <= MAX_K);
}

int uft(int N, int k, const std::vector<std::tuple<int, int, int>>& queries) {
    if (!InputValidation(N, k)) {
        std::cerr << "Error: Input constraints violated. N must be in range [1, " << MAX_N << "], "
                  << "and k must be in range [0, " << MAX_K << "]." << std::endl;
        return -1;
    }

    // init
    UnionFind uf(3 * N);
    int invalidCount = 0;

    for (const auto& query : queries) {
        int type = std::get<0>(query);
        int x = std::get<1>(query);
        int y = std::get<2>(query);

        if (x < 1 || x > N || y < 1 || y > N) {
            // Invalid animal number, skip this query
            invalidCount++;
            continue;
        }

        int xA = x, xB = x + N, xC = x + 2 * N;
        int yA = y, yB = y + N, yC = y + 2 * N;

        if (type == 1) {  // Same type
            if (uf.Find(xA) == uf.Find(yB) || uf.Find(xA) == uf.Find(yC)) {
                invalidCount++;
            } else {
                uf.Union(xA, yA);
                uf.Union(xB, yB);
                uf.Union(xC, yC);
            }
        } else if (type == 2) {  // x eats y
            if (uf.Find(xA) == uf.Find(yA) || uf.Find(xA) == uf.Find(yC)) {
                invalidCount++;
            } else {
                uf.Union(xA, yB);
                uf.Union(xB, yC);
                uf.Union(xC, yA);
            }
        }
    }

    return invalidCount;
}
