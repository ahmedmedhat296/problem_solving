"""
Script to rewrite problem.md files in a clearer, more convenient format
"""
from pathlib import Path

# Codeforces problems with their details
codeforces_problems = {
    "Game_with_Integers": {
        "name": "Game with Integers",
        "link": "https://codeforces.com/problemset/problem/1899/A",
        "contest_id": "1899",
        "index": "A",
        "rating": "800",
        "tags": "games, math, number theory"
    },
    "Vasilije_in_Cacak": {
        "name": "Vasilije in Cacak",
        "link": "https://codeforces.com/problemset/problem/1878/C",
        "contest_id": "1878",
        "index": "C",
        "rating": "900",
        "tags": "math"
    },
    "Candies_for_Nephews": {
        "name": "Candies for Nephews",
        "link": "https://codeforces.com/problemset/problem/2145/A",
        "contest_id": "2145",
        "index": "A",
        "rating": "800",
        "tags": "math"
    },
    "MEX_Partition": {
        "name": "MEX Partition",
        "link": "https://codeforces.com/problemset/problem/2160/A",
        "contest_id": "2160",
        "index": "A",
        "rating": "800",
        "tags": "math"
    },
    "Monocarps_String": {
        "name": "Monocarp's String",
        "link": "https://codeforces.com/problemset/problem/2145/C",
        "contest_id": "2145",
        "index": "C",
        "rating": "1200",
        "tags": "strings, greedy"
    },
    "Against_the_Difference": {
        "name": "Against the Difference",
        "link": "https://codeforces.com/problemset/problem/2135/A",
        "contest_id": "2135",
        "index": "A",
        "rating": "1000",
        "tags": "dynamic programming"
    },
    "Abrahams_Great_Escape": {
        "name": "Abraham's Great Escape",
        "link": "https://codeforces.com/problemset/problem/2155/B",
        "contest_id": "2155",
        "index": "B",
        "rating": "1000",
        "tags": "constructive algorithms, implementation"
    },
    "Bitwise_Reversion": {
        "name": "Bitwise Reversion",
        "link": "https://codeforces.com/problemset/problem/2153/B",
        "contest_id": "2153",
        "index": "B",
        "rating": "1100",
        "tags": "bitmasks, greedy"
    },
    "Circle_of_Apple_Trees": {
        "name": "Circle of Apple Trees",
        "link": "https://codeforces.com/problemset/problem/2153/A",
        "contest_id": "2153",
        "index": "A",
        "rating": "800",
        "tags": "math, implementation"
    },
    "Deck_of_Cards": {
        "name": "Deck of Cards",
        "link": "https://codeforces.com/problemset/problem/2145/B",
        "contest_id": "2145",
        "index": "B",
        "rating": "900",
        "tags": "greedy, implementation"
    },
    "Distincit_Elements": {
        "name": "Distinct Elements",
        "link": "https://codeforces.com/problemset/problem/2160/B",
        "contest_id": "2160",
        "index": "B",
        "rating": "900",
        "tags": "math, implementation"
    },
    "Math_Problem": {
        "name": "Math Problem",
        "link": "https://codeforces.com/problemset/problem/1227/A",
        "contest_id": "1227",
        "index": "A",
        "rating": "800",
        "tags": "math, implementation"
    },
    "Need_More_Arrays": {
        "name": "Need More Arrays",
        "link": "https://codeforces.com/problemset/problem/2114/C",
        "contest_id": "2114",
        "index": "C",
        "rating": "1200",
        "tags": "data structures, implementation"
    },
    "Split": {
        "name": "Split",
        "link": "https://codeforces.com/problemset/problem/2148/E",
        "contest_id": "2148",
        "index": "E",
        "rating": "1500",
        "tags": "greedy, math"
    },
    "Symmetrical_Polygons": {
        "name": "Symmetrical Polygons",
        "link": "https://codeforces.com/problemset/problem/2153/C",
        "contest_id": "2153",
        "index": "C",
        "rating": "1300",
        "tags": "geometry, math"
    },
    "The_Ancient_Wizards_Capes": {
        "name": "The Ancient Wizards' Capes",
        "link": "https://codeforces.com/problemset/problem/2155/C",
        "contest_id": "2155",
        "index": "C",
        "rating": "1400",
        "tags": "greedy, implementation"
    }
}

def create_problem_md(problem_info):
    """Create a clear, well-structured problem.md file"""
    name = problem_info["name"]
    link = problem_info["link"]
    contest_id = problem_info["contest_id"]
    index = problem_info["index"]
    rating = problem_info["rating"]
    tags = problem_info["tags"]
    
    content = f"""# {name}

## 📋 Problem Information

- **Problem Link**: [{name}]({link})
- **Contest**: {contest_id}
- **Problem Index**: {index}
- **Difficulty**: {rating}
- **Tags**: {tags}

---

## 📖 Problem Statement

Visit the [problem page on Codeforces]({link}) to read the complete problem statement, including:
- Detailed problem description
- Input/output format
- Constraints
- Sample test cases

---

## 💡 Quick Summary

This is a Codeforces problem from contest {contest_id}, problem {index}. The problem has a difficulty rating of {rating} and involves the following topics: {tags}.

For the complete problem statement, examples, and constraints, please visit the [official problem page]({link}).

---

## 🔗 Direct Link

**[View Problem on Codeforces →]({link})**
"""
    
    return content

def main():
    base_dir = Path(__file__).parent
    
    print("Rewriting problem.md files in a clearer format...")
    print("=" * 60)
    
    updated_count = 0
    
    for folder_name, problem_info in codeforces_problems.items():
        folder_path = base_dir / folder_name
        
        if not folder_path.exists():
            print(f"⚠ Folder not found: {folder_name}")
            continue
        
        problem_md_path = folder_path / "problem.md"
        
        # Create new problem.md content
        content = create_problem_md(problem_info)
        
        # Write to file
        with open(problem_md_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"✓ Updated: {problem_info['name']}")
        updated_count += 1
    
    print("\n" + "=" * 60)
    print(f"✅ Successfully updated {updated_count} problem.md files!")
    print("All files now have a clearer, more structured format.")

if __name__ == "__main__":
    main()

