package Kitikov_v4;

import java.util.*;

public class CharSet {
    int _capacity = 0;
    int _top = 0;
    char [] _arr = null;

    public CharSet() {
        _capacity = 16;
        _top = 0;
        _arr = new char [_capacity];
    }

    public CharSet(int n, boolean fill) {
        assert(n > 0);
        _capacity = n;
        _top = 0;
        _arr = new char [_capacity];
        if (fill) FillSet(n);
    }

    public CharSet(CharSet aSet) {
        assert(aSet != null);
        _capacity = aSet._capacity;
        _top = aSet._top;
        _arr = new char [_capacity];
        for (int i = 0; i < _capacity; ++i) {
            _arr[i] = aSet._arr[i];
        }
    }

    public CharSet(char [] arr) {
        assert(arr != null);
        _capacity = arr.length;
        _arr = new char [_capacity];
        for (int i = 0; i < arr.length; ++i) {
            this.Add(arr[i]);
        }
    }

    private boolean IsAllowed(char val) {
        return (val >= 32 && val < 256);
    }

    public int Find(char val) {
        assert(_top > 0);
        int a = 0, b = _top, c = 0;
        while(a < b) {
            c = (a + b) / 2;
            if (_arr[c] == val) return c;
            if (_arr[c] > val)
                b = c;
            else
                a = c + 1;
        }
        return b;
    }

    public boolean In(char val) {
        assert(IsAllowed(val));
        int pos = Find(val);
        return (pos != _top && _arr[pos] == val);
    }

    private void Allocate(int pos) {
        char [] newArr = _arr;
        _capacity = _top + 16;
        _arr = new char [_capacity];
        for (int i = 0; i < _top; ++i) {
            _arr[i] = newArr[i];
        }
    }

    public boolean Add(char val) {
        assert(IsAllowed(val));
        int pos = this.Find(val);
        if (pos != _top && _arr[pos] == val) return false;
        if (_top >= _capacity) this.Allocate(pos);
        for (int i = _top - 1; i >= pos; --i) {
            _arr[i + 1] = _arr[i];
        }
        _arr[pos] = val;
        ++_top;
        return true;
    }

    public boolean AddAll(CharSet aSet) throws Exception {
        assert(aSet != null);
        boolean flag = false;
        CharSetIterator it = new CharSetIterator(aSet);
        for (it.First(); !it.IsDone(); it.Next()) {
            if (this.Add(it.GetCurrent())) {
                flag = true;
            }
        }
        return flag;
    }

    private void FillSet(int n) {
        Random rnd = new Random(System.currentTimeMillis());
        while (this._top < n) {
            this.Add((char)(rnd.nextInt(256 - 32) + ' '));
        }
    }

    public boolean Remove(char val) {
        assert(IsAllowed(val));
        assert(!Empty());
        int pos = this.Find(val);
        if (pos != _top && _arr[pos] == val) {
            for (int i = pos + 1; i < _top; ++i) {
                _arr[i - 1] = _arr[i];
            }
            --_top;
        }
        else
            return false;
        return true;
    }

    public boolean RemoveAll(CharSet aSet) throws Exception {
        assert(aSet != null);
        boolean flag = false;
        CharSetIterator it = new CharSetIterator(aSet);
        for (it.First(); !it.IsDone(); it.Next()) {
            if (this.Remove(it.GetCurrent())) {
                flag = true;
            }
        }
        return flag;
    }

    public void Clear() throws Exception {
        _capacity = 16;
        _top = 0;
        _arr = new char [_capacity];
    }

    public CharSet Union(CharSet aSet) throws Exception {
        assert(aSet != null);
        this.AddAll(aSet);
        return this;
    }

    public CharSet Intersection(CharSet aSet) throws Exception {
        assert(aSet != null);
        CharSetIterator it = new CharSetIterator(this);
        for (; !it.IsDone();) {
            if (!aSet.In(it.GetCurrent())) {
                this.Remove(it.GetCurrent());
            }
            else it.Next();
        }
        return this;
    }

    public CharSet Difference(CharSet aSet) throws Exception {
        assert(aSet != null);
        CharSetIterator it = new CharSetIterator(this);
        for (; !it.IsDone();) {
            if (aSet.In(it.GetCurrent())) {
                this.Remove(it.GetCurrent());
            }
            else it.Next();
        }
        return this;
    }

    public boolean Empty() {
        return (_top == 0);
    }

    public void Print() throws Exception {
        System.out.print('[');
        if (Empty()) {
            System.out.print("Empty set");
        }
        else {
            CharSetIterator it = new CharSetIterator(this);
            for (it.First(); !it.IsDone(); it.Next()) {
                System.out.print("'" + it.GetCurrent() + "', ");
            }
        }
        System.out.print(']');
    }
}

class CharSetIterator {
    int _curr;
    CharSet _container;

    CharSetIterator(CharSet cont) throws Exception {
        if (cont == null) throw new Exception("Container is null!");
        _curr = 0;
        _container = cont;
    }

    boolean IsDone() { return (_curr >= _container._top); }

    char GetCurrent() throws Exception {
        if (IsDone()) throw new Exception("Iterator is done!");
        return _container._arr[_curr];
    }

    void First() { _curr = 0;	}

    void Next() { ++_curr; }
}
