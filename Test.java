public class Test {
    public static void main(String[] args) {
        String s = "The sky is blue ";
        System.out.println(reverseWords(s));
    }

    public static String reverseWords(String s) {
        String[] strs = s.trim().split("\\s+");
    
        for (int i = 0, j = strs.length - 1; i > j; i++, j--) {
            String tmp = strs[i];
            strs[i] = strs[j];
            strs[j] = tmp;
        }
        String res = "";
        for (String str : strs) {
            res += str;
            res += " ";
        }
        return res.substring(0, res.length() - 1);
    }
}
