using System;
using System.Text;
using System.Text.RegularExpressions;

namespace ConsoleApplication1 {
	class Test {
		private static Regex thousand = new Regex(@"^\d{4}$");
		private static Regex handred = new Regex(@"^\d{3}$");
		private static Regex overTwenty = new Regex(@"^[2-9]\d$");

		public static void Main(String[] args) {
			var sb = new StringBuilder();
			for (int i = 0; i < 1000; i++) {
				var text = (i + 1).ToString();
				sb.Append(GetLength(text));
			}
			Console.WriteLine(sb.ToString().Length);
			Console.ReadLine();
		}

		private static string GetLength(string text) {
			var sb = new StringBuilder(10);
			if (thousand.IsMatch(text)) {
				sb.Append(((Number)int.Parse(text.Substring(0, 1))).ToString());
				sb.Append(Number.Thousand.ToString());
				return sb.ToString();
			}

			if (handred.IsMatch(text)) {
				sb.Append(((Number)int.Parse(text.Substring(0, 1))).ToString());
				sb.Append(Number.Hundred.ToString());
				if (int.Parse(text.Substring(1, 2)) > 0) {
					sb.Append("And");
					sb.Append(GetLength(text.Substring(1, 2)));
				}
				return sb.ToString();
			}

			if (overTwenty.IsMatch(text)) {
				sb.Append(((Number)int.Parse(text.Substring(0, 1) + "0")).ToString());
				if (0 < int.Parse(text.Substring(1, 1))) {
					sb.Append(GetLength(text.Substring(1, 1)));
				}
				return sb.ToString();
			}

			return ((Number)int.Parse(text)).ToString();
		}

	}

	enum Number {
		Zero = 0, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Eleven, Twelve, Thirteen, Fourteen, Fifteen, Sixteen, Seventeen, Eighteen, Nineteen,
		Twenty = 20, Thirty = 30, Forty = 40, Fifty = 50, Sixty = 60, Seventy = 70, Eighty = 80, Ninety = 90, Hundred = 100, Thousand = 1000
	}

}
