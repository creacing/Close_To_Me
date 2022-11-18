<template>
  <div class="tag">
    <RouterLink class="link" :key="tag" v-for="tag in tagList" :to="tag.path" @click="clickTag(tag.name)"
      :style="{ 'font-size': tag.articlesNum > 20 ? '1.5rem' : tag.articlesNum < 14 ? '1rem' : `${tag.articlesNum * 1.5}px`, color: cloudColorList[tag.articlesNum % cloudColorList.length] }">
      {{ tag.name }}
    </RouterLink>

    <div class="content">
      <p v-for="row in tagRows" class="flex-row between">
        <span>{{ row.title }}</span>
        <span>{{ row.date }}</span>
      </p>
    </div>

  </div>

</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
import { store } from "@/stores/store.js";
import { ref } from "vue";
const state = store();
const { cloudColorList } = config;
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
