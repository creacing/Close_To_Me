<template>
  <div id="sidebar">
    <div>
      <h2>文章目录</h2>
    </div>

    <div class="content g--animation" data-title="文章目录">
      <ol>
        <li class="index-item" v-for="(item, index) in sideIndex" :key="item">
          <a href="#">
            <!-- <span>{{ index + 1 }}.</span> -->
            <span v-html="item" class="index--title"></span>
          </a>
        </li>
      </ol>
    </div>
  </div>
</template>
<script setup>
import { defineProps, toRefs } from "vue";

const props = defineProps({
  sideIndex: {
    type: Array,
    default: () => []
  }
})

const { sideIndex } = toRefs(props)

</script>
<style scoped lang='scss'>
#sidebar {
  width: 15rem !important;
}

.content .index-item {
  font-size: 1em;
  line-height: 1.8;
  overflow: hidden;
  text-overflow: ellipsis;
  white-space: nowrap;
}
</style>