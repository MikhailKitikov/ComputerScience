package BynarySortTree_package;

class Node<T extends Comparable<T>> {

    Node<T> left, right, parent;
    T value;

    // constructors

    Node() {
        this.left = null;
        this.right = null;
        this.parent = null;
        this.value = null;
    }

    Node(T value) {
        this.left = null;
        this.right = null;
        this.parent = null;
        this.value = value;
    }

    Node(T value, Node left, Node right, Node parent) {
        this.left = left;
        this.right = right;
        this.parent = parent;
        this.value = value;
    }
}
