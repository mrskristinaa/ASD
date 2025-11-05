class DSU {
	int* _parent;
	int _size;
	int* _rank;
public:
	DSU(int size);
	void unite(int, int);
	int find(int);
	~DSU();
};
DSU::DSU(int size) : _size(size) {
	_parent = new int[_size];
	_rank = new int[size];
	for (int i = 0; i < _size; i++) {
		_parent[i] = i;
		_rank[i] = 0;
	}
}
DSU:: ~DSU() {
	delete[] _parent;
}
int DSU::find(int x) {
	if (_parent[x] == x) {
		return x;
	}
	else {
		return find(_parent[x]);
	}
}
void DSU::unite(int x1, int x2) {
	if (_rank[x1] < _rank[x2]) {
		_parent[x1] = find(x2);
	}
	else {
		if (_rank[x1] == _rank[x2]) {
			_rank[x1]++;
		}
		_parent[x2] = find(x1);
	}
}