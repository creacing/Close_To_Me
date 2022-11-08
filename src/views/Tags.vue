<template>
  <div class="tag wrap">
    <RouterLink to="/">
      <h2 class="item title">
        <span>标签</span>
        <small>/</small>
        {{ tagsNum }}
      </h2>
    </RouterLink>
    <div class="tag cloud">
      <RouterLink
        :key="tag"
        v-for="tag in tagList"
        :to="tag.path"
        :style="{
          'font-size':
            tag.articlesNum > 20
              ? '30px'
              : tag.articlesNum < 14
              ? '20px'
              : `${tag.articlesNum * 1.5}px`,
          color: cloudColorList[tag.articlesNum % cloudColorList.length],
        }"
      >{{ tag.name }}</RouterLink>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
import { store } from "@/stores/store.js";
const state = store();
const { cloudColorList } = config;
const tags = state.tags;
const tagsNum = Object.values(tags).length;
const tagList = [];

for (const tag in tags) {
  tagList.push({ name: tag, path: "", articlesNum: tag.length });
}
</script>

<style lang='scss' scoped>
.tag {
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

  .item.title a {
    border-bottom: 0.0625rem dashed var(--grey-4);
  }

  .item.title:hover a {
    border-bottom-color: var(--color-blue);
  }
}
</style>
