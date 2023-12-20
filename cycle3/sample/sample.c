import math

class BinomialTree:
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.children = []
        self.parent = None

class BinomialHeap:
    def __init__(self):
        self.trees = []

    def merge_trees(self, heap2):
        self.trees.extend(heap2.trees)
        self.trees.sort(key=lambda x: x.degree)

    def link(self, tree1, tree2):
        tree1.parent = tree2
        tree1.sibling = tree2.children
        tree2.children.append(tree1)
        tree2.degree += 1

    def merge(self, heap2):
        self.merge_trees(heap2)

        if not self.trees:
            return

        i = 0
        while i < len(self.trees) - 1:
            current = self.trees[i]
            next_tree = self.trees[i + 1]

            if current.degree == next_tree.degree:
                if (i + 1 < len(self.trees) - 1 and
                        self.trees[i + 2].degree == next_tree.degree):
                    if next_tree.key < self.trees[i + 2].key:
                        self.link(next_tree, self.trees[i + 2])
                    else:
                        self.link(self.trees[i + 2], next_tree)
                    del self.trees[i + 2]
                else:
                    if current.key < next_tree.key:
                        self.link(current, next_tree)
                    else:
                        self.link(next_tree, current)
                    del self.trees[i + 1]
            i += 1

    def insert(self, key):
        new_heap = BinomialHeap()
        new_heap.trees.append(BinomialTree(key))
        self.merge(new_heap)

    def delete_min(self):
        if not self.trees:
            return None

        min_tree = min(self.trees, key=lambda x: x.key)
        self.trees.remove(min_tree)

        new_heap = BinomialHeap()
        new_heap.trees = min_tree.children
        self.merge(new_heap)

        return min_tree.key

def display_menu():
    print("\n1. Create Binomial Heap")
    print("2. Insert Key")
    print("3. Delete Min")
    print("4. Exit")

def main():
    binomial_heap = None

    while True:
        display_menu()
        choice = int(input("Enter your choice: "))

        if choice == 1:
            binomial_heap = BinomialHeap()
            print("Binomial Heap created.")
        elif choice == 2:
            if binomial_heap is

