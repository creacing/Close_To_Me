<template>
  <div class="collapse wrap">
    <h2 class="item title">
      <RouterLink to="/">分类</RouterLink>
      <small>/</small>
      {{categoryNum}}
    </h2>
    <div v-for="category in categories" :key="category">
      <h2 class="item header">
        <p :path="category.firstPath">{{category.firstTitle}}</p>
        <small>( {{category.firstNum}} )</small>
      </h2>
      <h3 class="item section">
        <p :path="category.secondPath">{{category.secondTitle}}</p>
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
import { ref } from "vue";
import { RouterLink } from 'vue-router'
import { store } from "@/stores/store.js";
const categoryNum = ref(0)
const state = store();

const posts = state.categoryDic

const categories = posts
</script>
<style scoped lang='scss'>
</style>