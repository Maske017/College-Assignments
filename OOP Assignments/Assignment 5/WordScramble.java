//Marin Aske
//COP3330
//Assignment 5: Stacks
//10/26/2024

import java.util.Stack;

public class WordScramble {

    public static String encode(String input) {
        Stack<Character> stack = new Stack<>();
        StringBuilder result = new StringBuilder();

        for (char ch : input.toCharArray()) {
            if (ch == '1') {
                // Do nothing for '1', starting a new group
                continue;
            } else if (ch == '2') {
                // When '2' is encountered, pop all items from stack (reversing order)
                while (!stack.isEmpty()) {
                    result.append(stack.pop());
                }
            } else if (isVowel(ch)) {
                // Only push vowels within a grouping (after '1', before '2')
                stack.push(ch);
            } else {
                // Append consonants directly to result
                result.append(ch);
            }
        }

        // Convert StringBuilder to a string for the final result
        return result.toString();
    }

    private static boolean isVowel(char ch) {
        return "aeiouAEIOU".indexOf(ch) != -1;
    }

    public static void main(String[] args) {
        System.out.println(encode("1top2"));           // Expected output: "tpo"
        System.out.println(encode("11top2e1cat22"));    // Expected output: "tpocta"
        System.out.println(encode("111tom2op2it2"));    // Expected output: "tmopti"
        System.out.println(encode("11top2i1tom22"));    // Expected output: "tpotmi"
    }
}

