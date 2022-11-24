<template>
  <div class="tag">
    <RouterLink
      class="link"
      :key="tag"
      v-for="(tag,index) in tagList"
      :to="tag.path"
      :style="{'font-size':  tag.articlesNum > 20 ? '1.5rem' : tag.articlesNum < 14 ? '1rem': `${tag.articlesNum * 1.5}px`, color: `var(--color-could${index+1})` }"
    >{{ tag.name }}</RouterLink>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
import { store } from "@/stores/store.js";
import { ref } from "vue";
const state = store();
const tags = state.tags;

const posts = state.posts
const tagList = [];


const tagRows = ref([])
const clickTag = (tag) => {
  tagRows.value = []
  for (const post of posts) {
    if (post.tags.includes(tag)) {

      console.log('tag-click', post.tags);

      tagRows.value.push(post)
    }
  }


}

for (const tag in tags) {
  tagList.push({ name: tag, path: "", articlesNum: tag.length });
}
</script>

<style lang='scss' scoped>
.tag {
  .link {
    display: inline-block;
    margin: 0.625rem;
  }

  .link:hover {
    color: var(--primary-color) !important;
  }

  .between {
    justify-content: space-between;
    margin-top: 1rem;
  }

  .between:hover {
    color: var(--color-blue);
  }
}
</style>
