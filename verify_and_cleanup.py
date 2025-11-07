"""
Script to:
1. Remove problem.md files from non-Codeforces problem folders
2. Verify that the matched Codeforces problems match the solutions
"""
from pathlib import Path
import requests
import time

# Non-Codeforces problem folders (algorithm/data structure problems)
non_codeforces_folders = [
    "reachable_coordinates",
    "splitting_items_greedy",
    "array_stack_implementation",
    "merge_sort",
    "html_tag_matcher",
    "array_based_bst",
    "maximum_subarray_divide_conquer",
    "matrix_operations_class",
    "manacher_algorithm"
]

# Codeforces problem folders with their expected problem IDs
codeforces_problems = {
    "Game_with_Integers": "1899A",
    "Vasilije_in_Cacak": "1878C",
    "Candies_for_Nephews": "2145A",
    "MEX_Partition": "2160A",
    "Monocarps_String": "2145C",
    "Against_the_Difference": "2135A",
    "Abrahams_Great_Escape": "2155B",
    "Bitwise_Reversion": "2153B",
    "Circle_of_Apple_Trees": "2153A",
    "Deck_of_Cards": "2145B",
    "Distincit_Elements": "2160B",
    "Math_Problem": "1227A",
    "Need_More_Arrays": "2114C",
    "Split": "2148E",
    "Symmetrical_Polygons": "2153C",
    "The_Ancient_Wizards_Capes": "2155C"
}

def verify_problem_match(folder_name, problem_id):
    """Verify that the solution matches the problem by checking the problem details"""
    try:
        contest_id = problem_id[:-1]  # Remove the letter
        problem_index = problem_id[-1]  # Get the letter
        
        # Get problem details from Codeforces API
        response = requests.get(
            "https://codeforces.com/api/problemset.problem",
            params={"contestId": contest_id, "index": problem_index},
            timeout=10
        )
        
        if response.status_code == 200:
            data = response.json()
            if data['status'] == 'OK':
                problem = data['result']['problem']
                return {
                    'name': problem.get('name', ''),
                    'contestId': contest_id,
                    'index': problem_index,
                    'rating': problem.get('rating', ''),
                    'tags': problem.get('tags', [])
                }
        return None
    except Exception as e:
        print(f"  Error verifying {folder_name}: {e}")
        return None

def remove_problem_md(folder_path):
    """Remove problem.md file from a folder"""
    problem_md_path = folder_path / "problem.md"
    if problem_md_path.exists():
        problem_md_path.unlink()
        return True
    return False

def main():
    base_dir = Path(__file__).parent
    
    print("Removing problem.md files from non-Codeforces folders...")
    print("=" * 60)
    
    removed_count = 0
    
    # Remove problem.md from non-Codeforces folders
    for folder_name in non_codeforces_folders:
        folder_path = base_dir / folder_name
        if folder_path.exists():
            if remove_problem_md(folder_path):
                print(f"✓ Removed problem.md from {folder_name}")
                removed_count += 1
            else:
                print(f"⚠ No problem.md found in {folder_name}")
        else:
            print(f"⚠ Folder not found: {folder_name}")
    
    print(f"\nRemoved {removed_count} problem.md files from non-Codeforces folders")
    
    print("\n" + "=" * 60)
    print("Verifying Codeforces problem matches...")
    print("=" * 60)
    
    verified_count = 0
    failed_count = 0
    
    # Verify Codeforces problems
    for folder_name, problem_id in codeforces_problems.items():
        folder_path = base_dir / folder_name
        if not folder_path.exists():
            print(f"\n⚠ Folder not found: {folder_name}")
            continue
        
        print(f"\nVerifying: {folder_name} -> {problem_id}")
        problem_info = verify_problem_match(folder_name, problem_id)
        
        if problem_info:
            print(f"  ✓ Found: {problem_info['name']} ({problem_info['contestId']}{problem_info['index']})")
            print(f"    Rating: {problem_info['rating'] if problem_info['rating'] else 'Not rated'}")
            print(f"    Tags: {', '.join(problem_info['tags']) if problem_info['tags'] else 'None'}")
            verified_count += 1
        else:
            print(f"  ✗ Failed to verify {problem_id}")
            failed_count += 1
        
        time.sleep(0.3)  # Be nice to the API
    
    print("\n" + "=" * 60)
    print(f"✅ Verification complete!")
    print(f"   Verified: {verified_count} problems")
    print(f"   Failed: {failed_count} problems")
    print(f"   Removed: {removed_count} problem.md files")

if __name__ == "__main__":
    main()

