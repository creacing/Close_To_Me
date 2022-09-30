<template>
  <div class="collapse wrap">
    <h2 class="item title">
      <RouterLink to="/">分类</RouterLink>
      <small>/</small>
      目前共计 {{categoryNum}}
      个分类
    </h2>
    <div v-for="category in categories" :key="category">
      <h2 class="item header">
        <RouterLink :to="category.firstPath">{{category.firstTitle}}</RouterLink>
        <small>( {{category.firstNum}} )</small>
      </h2>
      <h3 class="item section">
        <RouterLink :to="category.secondPath">{{category.secondTitle}}</RouterLink>
        <small>( {{category.secondNum}} )</small>
      </h3>
      <div class="item normal">
        <div class="title">
          <RouterLink :to="category.thirdPath">{{category.thirdTitle}}</RouterLink>
          <small>( {{category.thirdNum}} )</small>
        </div>
      </div>
    </div>
  </div>
</template>
<script setup>
import { ref } from "vue-demi";
import { RouterLink } from 'vue-router'
const categoryNum = ref(0)

const categories = [
  { firstPath: 'demo', firstTitle: 'demo', firstNum: 'demo', secondPath: 'demo', secondTitle: 'demo', secondNum: 'demo', thirdPath: 'demo', thirdTitle: 'demo', thirdNum: 'demo' }
]
</script>
<style scoped lang='scss'>
</style>