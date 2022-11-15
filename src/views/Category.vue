<template>
  <div class="category wrap">
   <RouterLink to="/"> <h2 class="item title">
      <span>分类</span>
      <small>/</small>
      {{categoryNum}}</RouterLink>
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
.category{
  small {
    color: var(--grey-4);
    margin: auto 0.3125rem;
  }

  .item {
    position: relative;
    padding: 1.25rem 1.875rem;
    margin: 0;
  }

  .item::before {
    content: "";
    position: absolute;
    z-index: 1;
    transition: all 0.2s ease-in-out 0s;
    box-sizing: unset;
    top: 1.9rem;
    left: 0;
    width: 0.6rem;
    height: 0.6rem;
    border: 0.15rem solid var(--primary-color);
    border-radius: 50%;
    background: var(--grey-1);
  }

  .item:not(:last-child):not(.title)::after {
    content: "";
    position: absolute;
    top: 1.9rem;
    bottom: -1.9rem;
    left: 0.35rem;
    border-left: 0.2rem solid var(--color-red-a3);
  }

  .item:hover::before {
    border-color: var(--color-blue);
  }

  .item.header::after {
    border-left-style: dashed !important;
  }

  .item.header .cheers {
    display: block;
  }

  .item.section::before {
    width: 0.4rem;
    height: 0.4rem;
    margin-left: 0.1rem;
  }

  .item.header a,
  .item.section a,
  .item.title a {
    border-bottom: 0.0625rem dashed var(--grey-4);
  }

  .item.header:hover a,
  .item.section:hover a,
  .item.title:hover a {
    border-bottom-color: var(--color-blue);
  }

  .item.normal {
    display: flex;
    flex-wrap: wrap;
    align-items: center;
    padding: 0.625rem 1.875rem;
  }

  .item.normal::before {
    top: 1.4rem;
    width: 0.2rem;
    height: 0.2rem;
    margin-left: 0.2rem;
    background: var(--primary-color);
  }

  .item.normal:hover::before {
    background: var(--color-blue);
  }

  .item.normal .meta {
    display: inline;
    font-size: 0.75em;
    margin-right: 0.625rem;
  }

  .item.normal .meta time {
    color: var(--grey-4);
  }

  .item.normal .title {
    display: inline;
  }

  .item.normal .title a {
    color: var(--primary-color);
  }

  .item.normal .title a:hover {
    color: var(--color-blue);
  }

  .item.normal .title .i-link-alt {
    font-size: 0.875em;
    margin-left: 0.3125rem;
  }
}

</style>