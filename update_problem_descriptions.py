"""
Script to search Codeforces for each problem and update problem.md files
"""
import requests
import json
import re
from pathlib import Path
import time

# Codeforces API endpoint
API_BASE = "https://codeforces.com/api"

# Problem name mappings - these are the folder names and their likely problem names
problem_mappings = {
    "Game_with_Integers": "Game with Integers",
    "Vasilije_in_Cacak": "Vasilije in Cacak",
    "Candies_for_Nephews": "Candies for Nephews",
    "MEX_Partition": "MEX Partition",
    "Monocarps_String": "Monocarp's String",
    "Against_the_Difference": "Against the Difference",
    "Abrahams_Great_Escape": "Abraham's Great Escape",
    "Bitwise_Reversion": "Bitwise Reversion",
    "Circle_of_Apple_Trees": "Circle of Apple Trees",
    "Deck_of_Cards": "Deck of Cards",
    "Distincit_Elements": "Distinct Elements",
    "Math_Problem": "Math Problem",
    "Need_More_Arrays": "Need More Arrays",
    "Split": "Split",
    "Symmetrical_Polygons": "Symmetrical Polygons",
    "The_Ancient_Wizards_Capes": "The Ancient Wizards' Capes"
}

def search_codeforces_problem(problem_name):
    """Search for a problem on Codeforces using the API"""
    try:
        # Get all problems
        response = requests.get(f"{API_BASE}/problemset.problems", timeout=10)
        if response.status_code != 200:
            return None
        
        data = response.json()
        if data['status'] != 'OK':
            return None
        
        problems = data['result']['problems']
        
        # Search for the problem by name (case-insensitive, partial match)
        problem_name_lower = problem_name.lower()
        for problem in problems:
            if problem_name_lower in problem.get('name', '').lower():
                return problem
        
        # Try exact match
        for problem in problems:
            if problem.get('name', '').lower() == problem_name_lower:
                return problem
        
        return None
    except Exception as e:
        print(f"Error searching for {problem_name}: {e}")
        return None

def get_problem_details(contest_id, problem_index):
    """Get detailed problem information"""
    try:
        response = requests.get(
            f"{API_BASE}/problemset.problem",
            params={"contestId": contest_id, "index": problem_index},
            timeout=10
        )
        if response.status_code == 200:
            data = response.json()
            if data['status'] == 'OK':
                return data['result']
        return None
    except Exception as e:
        print(f"Error getting problem details: {e}")
        return None

def clean_html(text):
    """Remove HTML tags from text"""
    if not text:
        return ""
    # Remove HTML tags
    text = re.sub(r'<[^>]+>', '', text)
    # Decode HTML entities
    text = text.replace('&lt;', '<').replace('&gt;', '>').replace('&amp;', '&')
    text = text.replace('&quot;', '"').replace('&#39;', "'")
    return text.strip()

def create_problem_md(problem_info, problem_details=None):
    """Create problem.md content"""
    problem_name = problem_info.get('name', 'Unknown Problem')
    contest_id = problem_info.get('contestId', '')
    problem_index = problem_info.get('index', '')
    rating = problem_info.get('rating', '')
    tags = problem_info.get('tags', [])
    
    problem_url = f"https://codeforces.com/problemset/problem/{contest_id}/{problem_index}"
    
    content = f"""# {problem_name}

## Problem Statement
<!-- Problem statement will be added from Codeforces -->

## Problem Link
[{problem_name}]({problem_url})

## Problem Details
- **Contest ID**: {contest_id}
- **Problem Index**: {problem_index}
- **Rating**: {rating if rating else 'Not rated'}
- **Tags**: {', '.join(tags) if tags else 'None'}

## Input Format
<!-- Input format will be added from Codeforces -->

## Output Format
<!-- Output format will be added from Codeforces -->

## Constraints
<!-- Constraints will be added from Codeforces -->

## Examples

### Example 1
**Input:**
```
<!-- Input here -->
```

**Output:**
```
<!-- Output here -->
```

### Example 2
**Input:**
```
<!-- Input here -->
```

**Output:**
```
<!-- Output here -->
```

## Note
Please visit the [problem page]({problem_url}) on Codeforces to see the complete problem statement, input/output format, constraints, and examples.
"""
    
    return content

def update_problem_md(folder_path, problem_name):
    """Update problem.md file for a given problem"""
    problem_md_path = folder_path / "problem.md"
    
    print(f"\nSearching for: {problem_name}")
    
    # Search for the problem
    problem_info = search_codeforces_problem(problem_name)
    
    if problem_info:
        print(f"  ✓ Found: {problem_info.get('name')} ({problem_info.get('contestId')}{problem_info.get('index')})")
        
        # Get detailed problem information
        contest_id = problem_info.get('contestId')
        problem_index = problem_info.get('index')
        
        if contest_id and problem_index:
            problem_details = get_problem_details(contest_id, problem_index)
        else:
            problem_details = None
        
        # Create problem.md content
        content = create_problem_md(problem_info, problem_details)
        
        # Write to file
        with open(problem_md_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        print(f"  ✓ Updated {problem_md_path}")
        return True
    else:
        print(f"  ✗ Not found on Codeforces")
        # Create a template with the problem name
        content = f"""# {problem_name}

## Problem Statement
<!-- Problem statement from Codeforces -->

## Problem Link
[Search on Codeforces](https://codeforces.com/problemset)

## Input Format
<!-- Input format -->

## Output Format
<!-- Output format -->

## Constraints
<!-- Constraints -->

## Examples

### Example 1
**Input:**
```
<!-- Input here -->
```

**Output:**
```
<!-- Output here -->
```

## Note
Please search for this problem on Codeforces and update this file with the complete problem details.
"""
        with open(problem_md_path, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"  ⚠ Created template (please update manually)")
        return False

def main():
    base_dir = Path(__file__).parent
    
    print("Searching Codeforces for problems...")
    print("=" * 60)
    
    found_count = 0
    not_found_count = 0
    
    for folder_name, problem_name in problem_mappings.items():
        folder_path = base_dir / folder_name
        
        if not folder_path.exists():
            print(f"\n⚠ Folder not found: {folder_name}")
            continue
        
        if update_problem_md(folder_path, problem_name):
            found_count += 1
        else:
            not_found_count += 1
        
        # Be nice to the API
        time.sleep(0.5)
    
    print("\n" + "=" * 60)
    print(f"✅ Update complete!")
    print(f"   Found: {found_count} problems")
    print(f"   Not found: {not_found_count} problems")
    print("\n💡 For problems not found, please search manually on Codeforces and update the problem.md files.")

if __name__ == "__main__":
    main()

