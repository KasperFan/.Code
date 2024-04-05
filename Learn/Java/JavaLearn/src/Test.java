import java.util.HashMap;
import java.util.Map;

class TrieNode {
    Map<Character, TrieNode> children;
    boolean isEndOfWord;

    public TrieNode() {
        children = new HashMap<>();
        isEndOfWord = false;
    }
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode current = root;
        for (char c : word.toCharArray()) {
//            current = current.children[c - 'a'];
            if (current == null) {
                return;
            }
        }
        current.isEndOfWord = true;
    }

    public boolean search(String word) {
        TrieNode current = root;
        for (char c : word.toCharArray()) {
//            current = current.children[c - 'a'];
            if (current == null) {
                return false;
            }
        }
        return current.isEndOfWord;
    }
}
public class Test {
    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("apple");
        trie.insert("bat");
        trie.insert("batman");
        trie.insert("apple");
        trie.insert("bat");
        trie.insert("app");
        System.out.println(trie.search("apple")); // 输出 true
        System.out.println(trie.search("bat")); // 输出 true
        System.out.println(trie.search("app")); // 输出 true
        System.out.println(trie.search("appetite")); // 输出 true
        System.out.println(trie.search("batman")); // 输出 true
        System.out.println(trie.search("banana")); // 输出 false
    }
}
