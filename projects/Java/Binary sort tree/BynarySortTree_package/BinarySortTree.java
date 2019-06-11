package BynarySortTree_package;

import java.util.ArrayList;

public class BinarySortTree<T extends Comparable<T>> {

    private Node<T> root;
    private int size;

    // constructors

    public BinarySortTree() {
        this.root = null;
        size = 0;
    }

    public BinarySortTree(Node<T> root) {
        this.root = root;
        if (root == null) {
            size = 0;
        }
        else {
            ArrayList<Object> elements = new ArrayList<>();
            this.InorderTraversal(elements, this.root);
            this.size = elements.size();
            this.root.parent = null;
        }
    }

    public BinarySortTree(Object [] elements) throws MyException{
        this.root = null;
        size = 0;
        try {
            for (Object element : elements) {
                this.Insert((T) element);
            }
        }
        catch (Exception e) {
            throw new MyException(1);
        }
    }

    // getters

    public Node<T> getRoot() {
        return root;
    }

    public int getSize() {
        return size;
    }

    // traversal

    // обход ЛЕВЫЙ-КОРЕНЬ-ПРАВЫЙ
    public void InorderTraversal(ArrayList<Object> elements, Node<T> tempNode) {
        if (tempNode == null)
            return;
        InorderTraversal(elements, tempNode.left);
        elements.add(tempNode.value);
        InorderTraversal(elements, tempNode.right);
    }

    // обход КОРЕНЬ-ЛЕВЫЙ-ПРАВЫЙ
    public void PreorderTraversal(ArrayList<Object> elements, Node<T> tempNode) {
        if (tempNode == null)
            return;
        elements.add(tempNode.value);
        PreorderTraversal(elements, tempNode.left);
        PreorderTraversal(elements, tempNode.right);
    }

    // обход ЛЕВЫЙ-ПРАВЫЙ-КОРЕНЬ
    public void PostorderTraversal(ArrayList<Object> elements, Node<T> tempNode) {
        if (tempNode == null)
            return;
        PostorderTraversal(elements, tempNode.left);
        PostorderTraversal(elements, tempNode.right);
        elements.add(tempNode.value);
    }

    // search

    public boolean Search(T val) throws MyException {
        if (this.root == null) {
            throw new MyException(3);
        }
        Node<T> tempNode = this.root;
        while(tempNode != null) {
            if (val.compareTo(tempNode.value) == 0) {
                return true;
            }
            if (val.compareTo(tempNode.value) > 0) {
                tempNode = tempNode.right;
            }
            else {
                tempNode = tempNode.left;
            }
        }
        return false;
    }

    // Insert

    public void Insert(T newVal) {
        if (this.root == null) {
            this.root = new Node<>(newVal);
            this.size++;
            return;
        }
        Node<T> tempNode = this.root;
        Node<T> newNode = new Node<>();
        while(tempNode != null) {
            newNode = tempNode;
            if (newVal.compareTo(tempNode.value) == 0) {
                tempNode.value = newVal;
                return;
            }
            if (newVal.compareTo(tempNode.value) > 0) {
                tempNode = tempNode.right;
            }
            else {
                tempNode = tempNode.left;
            }
        }
        if (newVal.compareTo(newNode.value) > 0) {
            newNode.right = new Node<T>(newVal, null, null, newNode);
        }
        else {
            newNode.left = new Node<T>(newVal, null, null, newNode);
        }
        this.size++;
    }

    // Remove

    public void Remove(T val) throws MyException {
        if (this.root == null) {
            throw new MyException(3);
        }
        Node<T> targetNode = this.root;
        while(targetNode != null) {
            if (val.compareTo(targetNode.value) == 0) {
                break;
            }
            if (val.compareTo(targetNode.value) > 0) {
                targetNode = targetNode.right;
            }
            else {
                targetNode = targetNode.left;
            }
        }
        if (targetNode == null) {
            throw new MyException(2);
        }
        // collecting elements from left and right subtrees
        ArrayList<Object> elements = new ArrayList<>();
        if (targetNode.left != null) {
            this.InorderTraversal(elements, targetNode.left);
        }
        if (targetNode.right != null) {
            this.InorderTraversal(elements, targetNode.right);
        }
        // deleting the node
        this.size -= (1 + elements.size());
        if (targetNode.parent == null) {
            this.root = null;
        }
        else {
            if (targetNode.parent.right == targetNode) {
                targetNode.parent.right = null;
            }
            else {
                targetNode.parent.left = null;
            }
        }
        // inserting saved elements
        for (Object element : elements) {
            this.Insert((T) element);
        }
    }

    // leaf count

    public int ToLeaf(Node<T> tempNode) {
        if (tempNode == null) {
            return 0;
        }
        if (tempNode.left == null && tempNode.right == null) {
            return 1;
        }
        return ToLeaf(tempNode.left) + ToLeaf(tempNode.right);
    }

    public int LeavesCount () throws MyException {
        if (this.root == null) {
            throw new MyException(3);
        }
        return ToLeaf(this.root);
    }

}
