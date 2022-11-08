<template>
  <div class="archive">
    <RouterLink to>
      <h2 class="item flex-row pos-rel">
        <span>归档</span>
        <small>/</small>
        {{ articlesNum }}
      </h2>
    </RouterLink>
    <RouterLink :to="`/article${archive.path}`" v-for="archive in archiveList" :key="archive">
      <h3 class="item flex-row pos-rel">
        <span class="bg">{{ archive.date.split("-")[0] }} 年</span>
        <small>/</small>
        <span class="bg">{{ archive.date.split("-")[1] }} 月</span>
        <small>/</small>
        <span class="bg">{{ archive.date.split("-")[2] }} 日</span>
        <small>/</small>
        <span class="bg">{{ archive.title }}</span>
      </h3>
    </RouterLink>
  </div>
</template>

<script setup>
import { RouterLink } from "vue-router";
import { store } from "@/stores/store.js";
import { ref } from "vue";
const state = store();
const posts = state.postsDic;

const articlesNum = state.postsDic.size;
const archiveList = ref([]);
for (const post of posts) {
  archiveList.value.push(post[1]);
}
</script>
<style scoped lang='scss'>
.archive {
  .item {
    padding: 1.25rem 1.875rem;
    margin: 0;
    .bg {
      padding: 0.125rem;
    }
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

  .item::after {
    border-left-style: dashed !important;
  }

  .item a {
    border-bottom: 0.0625rem dashed var(--grey-4);
  }

  .item:hover a {
    border-bottom-color: var(--color-blue);
  }
  small {
    color: var(--grey-4);
    margin: auto 0.3125rem;
  }
}
</style>