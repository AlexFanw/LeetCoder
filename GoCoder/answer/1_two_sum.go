package answer

func TwoSum(nums []int, target int)[] int{
	hashmap := map[int]int{}
	for k, v := range nums {
		if p, ok := hashmap[target-v]; ok{
			return []int{p, k}
		}
		hashmap[v] = k
	}
	return nil
}